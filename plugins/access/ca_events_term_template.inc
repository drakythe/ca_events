<?php

/**
 * @file
 * Plugin to provide access control based upon ca_event admin settings.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Event: term type'),
  'description' => t('Control access by event term type.'),
  'callback' => 'ca_events_term_template_access_check',
  'settings form' => 'ca_events_term_template_access_settings',
  'settings form submit' => 'ca_events_term_template_access_settings_submit',
  'summary' => 'ca_events_term_template_access_summary',
);

/**
 * Settings form for the 'by event term type' access plugin.
 */
function ca_events_term_template_access_settings($form, &$form_state, $conf) {
  $form['settings']['ca_events_term_template'] = array(
    '#type' => 'select',
    '#title' => t('Event\'s term template'),
    '#options' => array(
      'ca_events_term_template_one' => t('Template one'),
      'ca_events_term_template_two' => t('Template two'),
      'ca_events_term_template_three' => t('Template three'),
    ),
    '#required' => TRUE,
    '#default_value' => $conf['ca_events_term_template'],
  );

  return $form;
}

/**
 * Settings form submission.
 */
function ca_events_term_template_access_settings_form($form, &$form_state) {
}

/**
 * Check for access.
 */
function ca_events_term_template_access_check($conf, $context) {
  return $conf['ca_events_term_template'] == variable_get('ca_events_term_template', 'ca_events_term_template_one');
}

/**
 * Provide a summary description based upon the checked event term type.
 */
function ca_events_term_template_access_summary($conf, $context) {
  if ($conf['ca_events_term_template'] == 'ca_events_term_template_one') {
    $template = t('Template one');
  }
  elseif ($conf['ca_events_term_template'] == 'ca_events_term_template_two') {
    $template = t('Template two');
  }
  else {
    $template = t('Template three');
  }

  return t('Display template is set to: ' . $template);
}
